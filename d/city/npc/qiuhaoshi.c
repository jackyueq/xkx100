//Npc : qiu_haoshi.c

inherit NPC;
#include <ansi.h>

string ask_room1();
string ask_room2();

void create()
{
    set_name( YEL "���ʯ" NOR, ({"qiu haoshi", "qiu", "haoshi"}) );
    set( "title", "������ϥ԰����" );
    set( "age", 52 );
    set( "int", 30 );
    set( "con", 26 );
    set( "per", 18 );
    set( "attribute", "peaceful" );

    set( "long", @LONG
���ʯ�����ݵ���԰���ң���˵����������԰�Ӷ�����������С��
�����Ӳ��ߣ��Դ�ȴ�Ǽ�����īˢ��üë��СС���۾������
�ı��ӣ�����һ�����ࡣ
LONG
    );
    set( "combat_exp", 10000 );
    set_skill( "literate", 100);

    set( "inquiry", ([
        "С����ɽ��" : (: ask_room1 :),
        "�" : (: ask_room1 :),
        "����" : (: ask_room2 :),
        "���ú�Ժ" : (: ask_room2 :),
        "��" : "��ƽ��������������á�\n",
        "�Ⱦ�" : "��ƽ��������������á�\n",
        "��ϥ԰" : "�Ǻǣ�һ��С԰���ˡ�\n",
        "����" : "������������ҹ�����ζ��������ݣ�����������",
    ]) );
	set("chat_chance", 3);
	set("chat_msg", ({
        "���������ʯ������һ�ۣ�ȴʲôҲ��˵��",
        "��Ϊ�������ң�",
        "�αذ�ʱ���˷���������һ����ͷ�������أ�",
        "���������ʯ��̾һ����ת���ֿ�ʼ�Ⱦ��ˡ�"
    }) );
    setup();
    carry_object(CLOTH_DIR"jinduan")->wear();
}

int accept_object( object me, object ob )
{
    if ( userp(ob) ) return 0;
    if ( ob->query("name") == "ͨ��ѩ��" )
    {
        remove_call_out( "accepted" );
        call_out( "accepted", 1, me );
        return 1;
    }
}

void accepted(object me)
{
    command( "haha" );
    command( "tell " + me->query("id") + " �����κε�֪����ô˾ƣ�\n" );
    command( "en" );
    command( "tell " + me->query("id") + " ��������ɻ��ҵ�֪�޲��ԡ�\n" );
    command( "haha " + me->query("id") );
    command( "drink skin" );
    me->set_temp( "can_ask_qiu" );
}

string ask_room1()
{
    if ( this_player()->query( "can_ask_qiu" ) )
    {
        command( "say С����ɽ��������˼�ĵط����������ˣ�����\n"
         + "������ƺú��˵�������и���һ�£���ȴû��������\n"  );
        return "��ĵط��������ȥ�����������Ϸ��ҵ���԰������Ρ�";
    }
    else
        return "С����ɽ��������Ƶġ�";
}

string ask_room2()
{
    if ( this_player()->query( "can_ask_qiu" ) )
    {
        command( "say ���Ե���ǽ���û�����©����Ҳ���ߣ�Ҳ���������룬�Ǻǣ�\n"
         + "���������ص�һ������Ӳ��Ҵ���ġ�\n" );
        return "����һ���˿ɶ�����ȥ�ġ�\n";
    }
    else
        return "��������ǰ��֪�ݴ���������Ƶġ�\n";
}


