// Room: /d/taishan/yunuchi.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "��Ů��");
	set("long", @LONG
��Ů���ڱ�ϼ����ǽ�⣬ԭΪ�أ������Ϊ�����������ڶ���̩ɽ
ʱ������Ů���ڷ�����Ůʯ���������񣬽���������Ϊ��������Ů
��ϼԪ�������Ӵ�����ʢ��
LONG );
	set("exits", ([
		"east"  : __DIR__"bixia",
		"north" : __DIR__"sibeiya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
