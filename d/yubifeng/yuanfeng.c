// /yubifeng/yuanfeng.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "Բ��");
	set("long", @LONG
һ·ɽ���Ӷ����������ϣ���һ·ɽ���������򱱣���·ɽ�����
֮����������������Բ�յİ��塣�帲��ѩ��ӳ�����ԡ�
LONG );
	set("exits", ([
		"north"   : __DIR__"xiaolu3",
		"southup" : __DIR__"yuanfengding",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
