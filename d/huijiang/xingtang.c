// Room: /d/huijiang/xingtang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
�����Ǻ컨������á�����������׷��ʮ����ִ�ơ����е��Ӽ���
�������������������������Ҫ���侷��������л���Υ������������
���ĺ��ǣ�ʯ˫Ӣ��ִ����������׷���������Ų�ˬ���ǹʣ�����ɭ
Ȼһ������
LONG );
        set("objects", ([
		CLASS_D("honghua")+"/shi-shuangying" : 1,
        ]));
	set("exits", ([
		"north" : __DIR__"wuchang",
	]));
	set("coor/x", -50040);
	set("coor/y", 9130);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
