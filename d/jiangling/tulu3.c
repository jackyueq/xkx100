//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������·��ͨ����ɽ��Сɽ�塣������ûϥ�ĳ��ݣ�·����
ľ���н��ܡ�ɽ���⣬����������ˮ�ϵ��������̣����߿�ȥ������
��Ҫ���ˡ�һ�Իƺ����Ĵ�������ڲݴ��У�һ����ɵ�����һ���
�ɵ���������ֻ����ʼ�ղ��ֿ�������һ�����˹����ֲ�ɫ������С�
��ɽ����ףӢ̨�������ֺ������Ǵ���һ�ԣ�˫��˫�ɡ�
LONG );
	set("exits", ([
		"east"     : __DIR__"tulu2",
		"westup"   : __DIR__"tiandi",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1600);
	set("coor/y", -2200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}