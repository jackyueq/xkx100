string *food_name = ({
"�������", "Ѽ�˰���", "ǧ���͸�", "֥�����", 
});

string ask_secret()
{
    string food =  food_name[ random( sizeof( food_name ) ) ];
    command( "en" );
    command( "think" );
    command( "tell " + (string)this_player()->query( "id" ) + 
        " ��������" + food );
    this_player()->set_temp( "kid_ask/" + query( "id" ), food );
    return "��ô�����������ˣ��Ҿ͸����㣡\n";
}

int accept_object( object me, object ob)
{
    string food, id = me->query( "id" );
    food = (string)me->query_temp( "kid_ask/" + query( "id" ) ) ;
    if ( food && food == ob->name() )
    {
        command( "grin " + id );
        command( "tell " + id + " �ҵ������ǣ����ϰֽ�" 
        + query( "papa_name" ) + "��" );
        command( "laugh1 " + id );
        me->delete_temp( "kid_ask/" + query( "id" ) );
        return 1;
    }
    command( "look " + id );
    command( "sigh " + id );
    return 0;
}

