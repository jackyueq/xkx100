// Room: /d/jiaxing/jnroad4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����ڽ��ϵ�һ��ɽ·�ϣ�����ݺ�ɲݳ���ʱֵ���գ�·�Ե�ɽ��
�Ͽ����˽��ɫ���Ͳ˻��������ǽ������Ǽ��ˡ���������븣������
ɽ����������һ����·����Ϣ��С��ͤ��
LONG );
	set("exits", ([
		"north"   : __DIR__"jxnanmen",
		"west"    : __DIR__"jnroad3",
		"southup" : "/d/yanping/xianxialing",
		"east"    : __DIR__"chating",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
