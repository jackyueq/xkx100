// room: /d/xingxiu/shashan.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ɳɽ");
	set("long", @LONG
����һ����ɳ�ѻ��γɵĸ���ʮ�ɵ�ɳɽ��ɽ�嶸�ͣ����絶�С�
΢�紵����ɳɽ�������˵��������ʶ������˳�֮Ϊ��ɳɽ����ɽ��´
������Ȫ����ɽ���ɳ����������Ȫ��������ɽ���»�ɳ����������
׹�����������ڶ�����ζ��Ȼ���ʳơ�ɳ����������
    ɳ�����ƺ���һ�ֳ������䶯��
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northdown" : __DIR__"yueerquan",
		"eastdown"  : __DIR__"silk3",
		"west"      : __DIR__"wanxiangdong",
	]));
	set("objects", ([
		__DIR__"npc/shachong" : 1
	]));
	set("coor/x", -20320);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
