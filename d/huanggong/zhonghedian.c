// Room: /d/huanggong/zhonghedian.c

inherit ROOM;

void create()
{
	set("short", "�к͵�");
	set("long", @LONG
��������, �����û�, ����ǻ�������. ���ܳ���, ֧����صĴ�
�����ǰ˲�����. �������Ͻ������--�к͵�.
    �к�ȡ�ⲻƫ����, ����˵����Ҫǡ�����. �����Ľ��ܼⶥͤʽ
�����ǻʵ۵�̫�͵�μӴ��ǰ��Ϣ׼������ϰ���ǵĵط�. ÿ�괺��
֮��, �ʵ��ڴ��Ŀ����Ӻ�ũ��, ��ʾ����. 
LONG
	);
	set("exits", ([
		"north" : __DIR__"baohedian",
		"south" : __DIR__"taihedian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}