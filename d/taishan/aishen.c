// Room: /d/taishan/aishen.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
λ���չ۷��ϱߣ����ǰ����¡�������ԭ�������£������涸�ͣ�
������Ԩ����ʱ������Ϊ�ĸ���֣��������飬����������������
��Ѳ�����������²���ǽ���������������¡�
LONG );
	set("exits", ([
		"up"        : __DIR__"zhanlutai",
		"north"     : __DIR__"riguan",
		"southwest" : __DIR__"xianren",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 370);
	set("coor/y", 760);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
