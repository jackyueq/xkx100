//ROOM: /d/yanziwu/lixiang.c

inherit ROOM;

void create()
{
	set("short", "����Է");
	set("long",@LONG
Ľ�ݼҵĺ�ԺҲ���ڲ�ͬ��Բ��Ժ���Ͽ�������Է���֣�Ժ��ѩ��
���滨������֦ͷ��������ǽӴ�������������ˣ�������һ��������
���ȡ�
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"north" : __DIR__"chuantang",
		"west"  : __DIR__"longfeng",
		"east"  : __DIR__"changlang"
	]));
	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1520);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}