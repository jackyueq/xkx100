//Room: /d/dali/jingzhuang1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��һ��");
	set("long",@LONG
���Ĵ������񣬸�Լ�ĳߣ����״��У��ֳָ��ᣬ����ׯ�ء���
����̤��ū��һ��ū���Ⱪ���������ߣ�����������ū��������
��ū���͡�һ�����������ˣ��м�һ������˫�ָ�������һ�㡣����
֮�������ķ𾭡�
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang2",
	    "out"   : __DIR__"jinzhihe",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36000);
	set("coor/y", -70400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}