// Room: /d/nanshaolin/xianglu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¯");
	set("long",@LONG
�߹�ʯ��·�͵�������������¯�ԣ�����¯����ͭ���ͣ�������
���¯���Ͼ����ο��˶������޼�������ͳ��ѵķ�ҵ�ʡ�¯������
�������˵��Ƿ������֮����¯ǰ�㰸ǰ����λ������Զ���Ĥ�ݡ�
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"north" : __DIR__"stoneroad2",
		"south" : __DIR__"sblu-1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanbei" : 1,
		__DIR__"npc/xiang-ke" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

