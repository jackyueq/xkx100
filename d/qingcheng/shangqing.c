// Room: /qingcheng/shangqing.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "���幬");
	set("long", @LONG
���幬���Ͼ���������ǰɽ�ţ�������ͣ���Ϊ�鶯�����ڵ�
�ù�ɫ���ţ������̫���Ͼ���������������������ɽǰĦ��
ʯ�� "���µ�����ɽ" ���ƻ�񣬺���׳�ۡ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"westdown" : __DIR__"sanwanjiudao",
		"westup"   : __DIR__"huyingting",
		"west"     : __DIR__"yuanyangjing",
		"east"     : __DIR__"maguchi",
		"northup"  : __DIR__"qiandian",
	]));
	set("objects", ([
		__DIR__"npc/luo" : 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -880);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}