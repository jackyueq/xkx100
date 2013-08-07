// Room: /yangzhou/kedian.c
// Last Modified by Winder on Jul. 15 2000
#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", YEL"�ػ���Ԣ"NOR);
	set("long", @LONG
�������ػ���Ԣ���������ݵĿ��̴���ڴ�Ъ�š���Ԣ�ڰ���ܼ�
��������һ����̨����̨����һ���ʷ��������ڲ����������ӣ�һ�߻�
��֦�ʼ���ʲô��һ����С��������ĵ�����Ц������ӭ��ǰ��������
��¥��ǰ���Ÿ���ʾ(paizi)��
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n"+
"������ۣ�Ͷ�꣺bid��Ԥ����deposit�����ۣ�setprice;״̬��status \n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/popo" : 1,
	]));
	set("exits", ([
		"up"    : __DIR__"kedian2",
		"east"  : __DIR__"majiu",
		"west"  : __DIR__"shilijie5",
		"north" : __DIR__"ganquanjie",
	]));

	set("coor/x", 20);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian_b"->foo();
	"clone/npc/xiang"->move(this_object());
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && ( dir == "west" || dir == "north"))
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
void init()
{
	object me=this_player();
	if (me->query("name")=="����" && me->query("id")!="qingyun")
	  me->set("name","������ͷ");
}