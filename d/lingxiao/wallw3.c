// Room: /d/lingxiao/wallw3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ");
	set("long", @LONG
����Į����ֱ����������Բ����Ҳֻ�������־��򺮵أ����д���
�����澰�������ձ���ɽ���������������ž������Ĵ�Į֮�ϣ�����
������ֱ��������εΪ��ۡ���Ұ������һ������Į�ĳ��ӣ�����ס
�˺������ա���ɫ������ֱ�������һ�������ȥ���̶�һ�����ʱ
���ڣ����˵���꣬ҲΪ֮�𺳡� 
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east" : __DIR__"wallw2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31030);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup(); 
	replace_program(ROOM);
}

