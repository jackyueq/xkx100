inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ǿ������ã�һ���������ں�Ѿ�������졣�ϱ��ǿ���
��Ժ���������鷿��������һ�����á�
LONG );
	set("exits", ([
  		"west"  : __DIR__"fotang",
  		"north" : __DIR__"shufang",
  		"south" : __DIR__"kang3",
	]));
	set("objects", ([
  		__DIR__"npc/puyi": 1,
  		__DIR__"npc/yahuan": 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4083);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
