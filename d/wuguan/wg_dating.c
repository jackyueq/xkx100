// wg_dating.c

inherit ROOM;

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
��������ݴ��������п�������һ�Ű����������Ϲ��Źع�����λ��
�Ա߷���������ɻ�ƿ�����ż�֧��ȸ�ᣬǽ��д�Ŵ���һ�����䡱
�����������Щ���ڽ����ϴ������ֽ�ϴ�����ˣ������ݿ����������
�ݣ��������Ǹ����ȣ�һֱͨ����������ҡ�
LONG);
	set("exits", ([
		"enter"     : __DIR__"wg_lang5",
		"westdown"  : __DIR__"wg_dayuan2",
		"northdown" : __DIR__"wg_shilu-2",
		"southdown" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_chen" : 1,
	]));
	set("coor/x", 31);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
	"/clone/board/wuguan_b"->foo();
}


