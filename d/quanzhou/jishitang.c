// Room: /d/quanzhou/jishitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�������ϵ�");
	set("long", @LONG
���Ǽ����ֺŵ���ҩ�̣�����������Ũ���ҩζ����ǰ����һ����
���̨����̨����һ��˶���ޱȵ�ҩ�񣬼�����ס������ǽ����������
������ʢҩ��С���룬ÿ�����������С�֣�ע��ҩ�����ơ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east"    : __DIR__"yaofang",
		"enter"   : __DIR__"neitang",
		"north"   : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
