// Room: /d/yueyang/nanjie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "�Ͻ�");
	set("long", @LONG
����һ���ֳ��ֿ����ʯ����������ǿ͵꣬�����Ƿ��꣬������
���������Ŀ��̱ص�֮�������Ҳ��ȫ�������ֵĵط������ߵ�С����
�����²�ͣ���������⣬һЩ��å�Ͳ���������ؤ��Ҳ�������г˻���
�ͣ�����ﺰ��Сϱ���֣����һƬ��
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"kedian",
		"west"  : __DIR__"jiudian",
		"north" : __DIR__"zhongxin",
		"south" : __DIR__"nanmen",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/liu-zhuzhuang" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
