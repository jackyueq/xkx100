// Room: /d/songshan/fawangsi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ɽ�������£���Լ��ï�������У�������̫�ң�������
���룬����һ�����ӣ���ɲλ���м䡣�����½��ڶ���������ƽʮ����
����Ԫ��ʮһ�꣩���Ƿ�̴����й������������Ժ���Ǻ�����רΪ
ӡ�ȸ�ɮ��Ħ�ں��÷����뾭���̶�뷽��ģ���Ϊ�й���һ�����������
��ģ��󣬽ṹ�Ͻ�������¥�󣬽�̻Ի͡�
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao4",
		"northeast" : __DIR__"shandao5",
		"northup"   : __DIR__"tayuan",
		"west"      : __DIR__"yuetai",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/gao": 1,
		__DIR__"npc/dizi" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 810);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
