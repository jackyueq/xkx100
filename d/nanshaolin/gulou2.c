// Room: /d/nanshaolin/gulou2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
ÿ��¥���϶������˽�ʵ��ľ¥�壬�˽��ε�ǽ�����������ȴ�
�����Ӵ��׿���ǽ��Ҳ�Ǽ�Ϊ��ʵ���������������������Կ���Χ����
�ܵ�С԰�Լ����ߵ����֣����Ʈ��������Ҷ�����㡣
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou3",
		"down" : __DIR__"gulou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



