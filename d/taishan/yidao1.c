// Room: /d/taishan/yidao1.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ������
����������߷ɳ۶���������һ·���������ϵ��˸������ž�װ����
���������еĻ���������ŵ�������������Щϰ��Ľ����ˡ���·����
����������������֡�
LONG );
	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
		"southeast" : "/d/jiaxing/jnroad1",
	]));
	set("objects",([
		__DIR__"npc/tangzi" : 2,
                "/d/quanzhou/npc/hai" : 1,
                "/d/city/npc/xiaoguiz" : 1,
	]));
	set("outdoors", "jiangnan");
	set("coor/x", 300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
