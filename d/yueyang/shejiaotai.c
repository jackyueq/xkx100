// Room: /d/yueyang/shejiaotai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����̨���������֣��ھ���ͤ���档����һ���ն������Զ�ͥ����
�ľ�ʯ���ഫ������һ���ԣ���ˮ���˷����ˣ������˲ƣ��������֮
���ʱ�Ѳ�����ھ�ɽ�������ֿڡ���ʯ�����и����׼���ƽ�棬������
�����߶೤�ľ޴��ӡ����Ϊ���������ʱ���µ�ʥ������̨�����͡�
�վ���һ�壬Ϊ��ɽ�˾�֮һ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"xiaolu2",
		"westup" : __DIR__"shijie3",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/song" : 1,
	]));
	set("coor/x", -1740);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
