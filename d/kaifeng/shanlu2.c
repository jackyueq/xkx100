// /kaifeng/shanlu2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create ()
{
	set ("short", "ɽ·");
	set ("long", @LONG
����һ�����������ɽ·����Ϊ����ɽ�ȼ���ɽ�����Ƚ�Զ������
�����ǿ�����·�����������˺ܶ࣬·�������Զ���и�Сͤ�ӹ�����
Ъ�ţ����߲�Զ������ɽ��
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"north"  : "/d/songshan/taishique",
		"eastup" : __DIR__"shanlu1",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
