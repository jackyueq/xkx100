// santan.c
// Date: Nov.1997 by Venus
#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", "��̶ӡ��");
        set("long", @LONG
����������С��޵ġ�������Ӧ��ͤ��С����˳ơ������е�����
���к�����ͤǰ����Ի�������п��뻭�л�  ¥��¥��ɽ��ɽ��������
����Ϊ��������ʱ����������Ӱͤͤ������������������������������
��ʹ����̶ӡ�¡�λ������ʮ����
    Ԫ���������٣����������ؽ�ʱ�Ѳ���ԭ�����³ɽ�ʱ��������һ
�֣�����Ӱ������֮����ͤ�߲���С��(zhou)�����ο�ȥ�յ̡�
LONG);
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4130);
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
	message_vision("�ҹ�һ�������ϴ�����ҡľ����С�����С�\n", ob);
	ob ->move(__DIR__"xihu") ;
	tell_object(ob, HIG "���ں��洩�У����������������ů��\n" NOR ) ;
	call_out("tostyy", 10 , ob );
	return 1 ;
}
void tostyy(object ob )
{
	tell_object(ob , "С�����῿���յ̡������´�����\n" ) ;
	ob->move (__DIR__"suti6") ;
}
