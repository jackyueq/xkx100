// /d/beihai/qianmen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
�����Ǳ�����ǰ�ţ����ڱ�����ר�Ź��ʹ��������ֵĵط�������
һ���ǽ�������ͨ�ϰ����ǲ����Խ�ȥ�ġ��������ɫ�ģ�����Ϲ���
һ����(bian)���ſ�վ��������ʿ��
LONG
	);
	set("cost", 2);
	set("item_desc", ([
		"bian" : "����һ���ɫ���ң������ý���д���ĸ�����:���� ��Է\n",
	]));
	set("exits", ([
		"east"      : __DIR__"shulin",
		"southwest" : __DIR__"zhaojing",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
