// shulin1.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һƬС���֣���Χ����ľ���ܸߡ�������һЩ�в������ֵ���
��������ͷס�����������Щ����������������·�˰ɣ�תͷ��ȴ����
���ϱ��ƺ���һ��С·������������֮�С�
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northdown" : __DIR__"shulin0",
		"southwest" : __DIR__"shulin2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
