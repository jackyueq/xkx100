// Room: /yangzhou/shanmen.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long",@LONG
ɽ����Ƕ�������¡�ʯ����ƴ������鷨�������ּ���ɽ�Ŷ���
��ǽǶʯ�̸�һ����Ϊ��������һ�ۡ���¼�عۡ�������ƽɽ���ϡ��䣬
�������鷨�ҽ����飻��Ϊ������Ա���������顰���µ���Ȫ����
    ����ʱ�ɻ䡰���������֣��س������£�Ǭ¡Ѳ�����ݣ��ױʸ���
�������¡����׳ơ�ƽɽ�á���
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north"     : __DIR__"tianwangdian",
		"southdown" : __DIR__"pailou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 140);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}