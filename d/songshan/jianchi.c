// Room: /d/songshan/jianchi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
û�����ۼ�����û�����˻����ţ�������ɽ����֮�ϣ���Ȼ������
ô��һ��ˮ��һ���������ɵ�������պ���ˮ���ϣ����п����������
������������ɽ�ɹ߳�ʹ�õĽ���
    ˮ���������졣�����г��ȿ�ˮ������
LONG );
	set("exits", ([
		"south" : __DIR__"huimengtang",
		"east"  : __DIR__"eastpath1",
		"west"  : __DIR__"westpath1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		CLASS_D("songshan")+"/tang" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
