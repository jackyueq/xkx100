// Room: /d/songshan/chanyuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
������Ժ����ɽ������Ժ�йŰ�ɭɭ�����ϲ��޷���Ժ��������
����ǧ�ˡ����������ɽ�ɵı�Ժ�ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"qianting",
		"north" : __DIR__"zhongmen",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/fei" : 1,
	]));
	set("valid_startroom",1);
	set("coor/x", -20);
	set("coor/y", 870);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
	"/clone/board/songshan_b"->foo();
}
