// Room: /yangzhou/shiliji1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ﳤ��");
	set("long",@LONG
����ʮ�ﳤ�֣������ֱ߾�¥��������¥�߸󣬻�����ӳ��ÿ����
ҹ�����ƹݲ�¥�����������������οͻ������У������¥������Ů��
ʢױ��������������������˾�����������������ʫ�䣺��ҹ��ǧ����
���ƣ���¥����ͷ׷ס���������˷��������ݣ���֪ʢ�Ƶ����ݸ���
����ʢ����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"xiaobaozhai",
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"shilijie2",
		"north" : __DIR__"beimendajie",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/youfang" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
