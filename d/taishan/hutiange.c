// Room: /d/taishan/hutiange.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ȡ�Ե����Ժ���Ϊ�ɾ�֮�⡣���������ɸ���Ǭ¡�ʵ�
���ʱ�ؽ��Ľ�������Ϊ�����¥ʽ���������������ӳ����������
�������¿��龳����·�������΢����͢����������Ǵ�ɽһ�����Ǻ�
�죬�켫��ǧ���жร�ء����Ŷ���˫����ǽ�к������������ϣ�����
�澰��
LONG );
	set("exits", ([
		"westup"    : __DIR__"huima",
		"southdown" : __DIR__"sihuaishu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 650);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
