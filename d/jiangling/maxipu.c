//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
���������������Ͻ�����Ϫ���£���СϪ�ԡ������ߵ�����С��֮
ǰ����һ��ɹ�ȳ�����ǰ����������һ����ͷ��������ҧ��һ���̶̵�
���̹ܣ��������ڴ��Ь���������⴩���������������һ�������̣�
��������ͷ�׷�����������֮�ϣ���������Ƴ��һ��ʱ��������⾼Ȼ��
�����������������������ʵҲ�������ϣ��ƺ���ʮ��Ҳ��������
LONG );
	set("exits", ([
		"east"   : __DIR__"caidi",
		"north"  : __DIR__"tiandi",
		"westup" : __DIR__"tulu4",
	]));
	set("objects", ([
		__DIR__"npc/qichangfa" : 1,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1610);
	set("coor/y", -2210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}