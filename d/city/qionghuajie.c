// Room: /yangzhou/qionghuajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����������ʯ�̵أ�����ȴ�����ѷ죬Ҳ��ƽ�������������
���Ͻֵ�Ե�ʡ����ߵ������������أ����Ӷ���������С�ﴩ�����С�
���˴��ҴҶ�����żȻ������Ļ���ʯ�ġ����ա�����������ǳ���
��Ժ���������ڴ˴���ѧ�ʡ�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"east"   : __DIR__"kaimingqiao",
		"west"   : __DIR__"beimendajie",
		"south"  : __DIR__"chaguan",
		"north"  : __DIR__"shuyuan",
	]));
	set("coor/x", 20);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}