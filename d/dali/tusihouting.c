//Room: /d/dali/tusihouting.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���������Ǻ�������һ¥һ�׵���ʽ�������ݽǵ��ϸ�ܣ�����
����������ͼ�������޻�ľ�ĵ�̣�������������·��ӱ����������
ʮ������˾���б�����õ�һ����
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"tusimentang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", -71000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}