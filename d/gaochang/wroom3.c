// Room: /d/gaochang/wroom3.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
ÿһ�䷿�д󶼹��з���żȻ�ڱ��ϼ����������ģ�д���ǡ���
����������������̩�������������ʮ���꡹�ȵ���������һ��������
���Ķ��Ǻ�����������д���ǡ������ʥ��ʦ����λ�������Ҹ�����
ʮ�ˣ�д�����ջء�������·�������ӹ����������ġ��������š�����
�֡�
LONG
	);
	set("exits", ([
		"south" : __DIR__"wroom2",
		"northwest" : __DIR__"zoulangw",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36510);
	set("coor/y", 10070);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}