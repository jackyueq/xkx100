// /yubifeng/zoulang4.c
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
		"east"  : __DIR__"eastroom1",
		"north" : __DIR__"zoulang6",
		"south" : __DIR__"zoulang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6130);
	set("coor/y", 5190);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

