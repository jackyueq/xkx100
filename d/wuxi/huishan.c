// Room: /d/wuxi/huishan.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��ɽɽ��");
	set("long", @LONG
���ϻ�ɽɽ����������ɽ���ɴ�Լ�������Դ䣬��Ժʯ����ΡȻ
�������Ӵ˿�Զ������ȫ�Ǻͺ���̫������ɽԭ����ɽ��ɽ������
�������ɾ����������ڵ�һʯ�������飺������������������������
�����塣�������˳�������
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown"  : __DIR__"road15",
	]));
	set("coor/x", 260);
	set("coor/y", -160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}