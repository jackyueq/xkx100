// Room: /d/wuxi/huishanquan.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "���µڶ�Ȫ");
	set("long", @LONG
��ǰ�Ѿ�������ɽɽ�ţ�ֻ�����ɱ��գ����������졣��ɽʯ��
֮�ԣ���һԲһ�����أ�Բ�����ϣ��������¡�����ͷ������ף���
�͹��ӣ�Ȫˮ(quan)�����ڳ����򱱼����ϵû�ɽ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"road14",
		"northup"  : __DIR__"road15",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));
	set("item_desc", ([
		"quan" : "��ǰһ����Ȫ������ǣ��ص׾�ʯ�������ɼ���\n",
	]));
	set("coor/x", 260);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}