//TOJMQ1.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ͨ����ľ��Ĵ������·��������ſ���ʮ�˲�����С���
�ھ�ľ��������������������࣬���ع������ӵġ������ػ�������Χ��
���������������з��ݺ�ջ�ŵĽ��졣
LONG );
	set("exits", ([
		"northwest" : __DIR__"tojmq2",
		"southeast" : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52040);
	set("coor/y", 840);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}