// Room: /d/yueyang/dongtingmiao1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ͥ������");
	set("long", @LONG
��ͥ��λ�ھ�ɽ������������İ�ɽ������������Ъɽ��������Ͳ
�ߡ�˫����ɽǽ����������ܶ����������ص��á�����������һ����Ŀ
�����ĺ����������������㱻����Ϊ��ͥ�����������������������
����סˮ��½�֣�����Ǯ�������˹���ߣ�������������Ѳ�������
�������¹���ߣ����ǣ�������ɰ�����������˺���������
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"xiaolu8",
		"east"  : __DIR__"yinyangting",
		"west"  : __DIR__"taijiting",
		"north" : __DIR__"dongtingmiao2",
	]));
	set("coor/x", -1660);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
