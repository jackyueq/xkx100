// garden.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","��԰");
	set("long",@LONG
����һ��԰�ӣ�ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��
׾���������壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��С
ͤ�ӣ�����Ϫˮ��������ȥ������ͨ��������Ϊ����������һ�����ȣ�
����С�ݴ���������ζ������������ȥ������
LONG);
	set("exits",([
		"east"      : __DIR__"buwei1",
		"west"      : __DIR__"chufang",
		"north"     : __DIR__"changlang",
		"south"     : __DIR__"shufang",
		"southwest" : __DIR__"houyuan",
	]));
	set("outdoors", "huashan");
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
