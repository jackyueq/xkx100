// Room: /d/taohuacun/taohua2.c

inherit ROOM;

void create()
{
	set("short", "�һ�Ϫ");
	set("long", @LONG
���һ������һ�Ϫ���һ�Ϫˮ����ϴ�����Ӹ��ƿ����գ����
��Ů����ϡ������������һ�Ϫ������С�����һ����л���ʱ����
����ʱ��ƬƬ�ɺ��׹Ϫ�У���ˮ��ȥ��������ϧ��������Ϫ�ϣ�
����˼�ˣ��������ޡ� 
LONG );
	set("outdoors", "taohuacun");
	set("no_clean_up", 0);

	set("exits", ([
		"westup" : __DIR__"taohua3",
		"south"  : __DIR__"taohua1",
		"north"  : __DIR__"taohua6",
	]));
	set("coor/x", -100);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}