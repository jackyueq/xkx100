// /yubifeng/zoulang6.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ͨ��������˵����ҡ�����ľ���ϻ���л�
����棬�����Щ��ʱ�˵��ֻ���ÿ���߰˲�������һ����̨��������
�̴�ͭ�������γ�����֮����һ��
LONG);
	set("exits", ([
		"east"  : __DIR__"eastroom2",
		"west"  : __DIR__"houting",
		"south" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6130);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

