// /yubifeng/zoulang1.c
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
		"east"  : __DIR__"dating",
		"north" : __DIR__"zoulang3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5180);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

