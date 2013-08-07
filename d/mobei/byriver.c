// Room: /d/mobei/byriver.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
��ԭ�ϵ�һ��Сˮ���������Ǽ��ð��ή�����������ߵ���ݰ���
�˵�ˮ�У���ˮ��Щ���ǡ����ı����Ǹ������������Ǹ��ɲݶѣ��Ա�
��һ��Сé����Ȼ��ª����Ȼ�ܿ������ϵķ��
LONG
	);
	set("outdoors", "mobei");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"river",
		"northeast" : __DIR__"chulan",
		"east" : __DIR__"caodui",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
