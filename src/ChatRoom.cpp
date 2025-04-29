#include "ChatRoom.hpp"

void ChatRoom::broadcast(const std::string& message, std::shared_ptr<Client> except_part)
{
    for (auto& participant : participants)
    {
        if (participant != except_part)
        {
            participant->deliver_to_client(message);
        }
    }
}

void ChatRoom::join_participant(std::shared_ptr<Client> participant)
{
    if (!is_member(participant->get_uid()))
    {
        participants.insert(participant);
        broadcast("Participant joined: " + participant->get_nickname() + "\n\r", participant);
    }
    else
    {
        participant->deliver_to_client("You are already member of chat: " + room_name + "\n\r");
    }
}

void ChatRoom::leave_participant(std::shared_ptr<Client> participant)
{
    if (is_member(participant->get_uid()))
    {
        participants.erase(participant);
        broadcast("Participant left: " + participant->get_nickname() + "\n\r", participant);
    }
    else
    {
        participant->deliver_to_client("You aren't member of this chat: " + room_name + "\n\r");
    }
}

bool ChatRoom::is_admin(USER_ID_T participant_id) const
{
    return _admin_uid == participant_id;
}

bool ChatRoom::is_member(USER_ID_T user_uid) const
{
    for (auto& chat_participant : participants)
    {
        if (user_uid == chat_participant->get_uid())
        {
            return true;
        }
    }
    return false;
}