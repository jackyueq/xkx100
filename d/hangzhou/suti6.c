// suti6.c
// Date: Nov.1997 by Venus
#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
����֮ҹ�����¹ۺ���Ψ�������������ԣ�����΢�磬���й���Ʈ
�㣬����Ϊ֮�����̱߲���С��(zhou)�����ο�ȥ��̶ӳ�µġ�����
����ȥ���ۣ�����ɼ���̶ӳ��ң�����У������������ţ�����ӳ���š�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti5",
            "south"     : __DIR__"suti7",
            "west"      : __DIR__"huagang",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4110);
	set("coor/y", -1440);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob ;
	string dir;
	if( !arg || arg !="zhou" ) 
	{
		tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		return 1 ;
	}
	ob = this_player () ;
	message_vision("�ҹ�һ�������ϴ�����ҡľ����С�۶��С�\n", ob);
	ob ->move(__DIR__"xihu") ;
	tell_object(ob, HIG "���ں��洩�У����������������ů��\n" NOR ) ;
	call_out("tostyy", 10 , ob );
	return 1 ;
}
void tostyy(object ob )
{
	tell_object(ob , "С�����῿�Ϻ���С��ޡ������´�����\n" ) ;
	ob->move (__DIR__"santan") ;
}
