// Room: /d/heimuya/didao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ص�");
	set("long", @LONG
��������һ���ص�������������̫ƽ�����������Եļ�յ�͵ƣ���
���綹���ǿ���ȥǰ�����й�������Ҫ�Ǿ��ú��£����ڻ�ͷ���ǿ���
�ģ��������쳣���ľ�ȴҲ���󼤷�����ĺ����ģ����ɷ����ֺ����
�գ����������ɼѡ�
LONG );

	set("exits",([
		"down"  : "/d/city/shilijie4",
		"west"  : __DIR__"didao1", 
		"south" : __DIR__"didao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
