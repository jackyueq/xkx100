// Room: /d/taishan/fengchan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ���
�����������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨�ϰڷ���
�����������������ڴ��������¡�̨�ϸ߸�����һ���죬���飺����
���е����ĸ����֡��������Ҹ���������λ������ʿ�����߶�����һ��
�Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�������
LONG );
	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));
	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));
	set("outdoors", "taishan");
	set("coor/x", 410);
	set("coor/y", 630);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
