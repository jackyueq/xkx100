//Room: /d/dali/yanchi1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�سص̰�");
	set("long",@LONG
�����غ��̰���ֲ��ɫ����ܰ�������ֳơ�����ӡ���������һ����֧��
�̰����ֻ�ɫ��ӭ�������ʳơ�����ӡ������֭�ӡ�����ͬΪ��صĳ�ˮ
�ڣ��ֳƺ��ڡ�
LONG);
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"    : __DIR__"dianchi",
	    "west"     : __DIR__"jinzhihe",
	    "eastup"   : __DIR__"yanchi2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -35000);
	set("coor/y", -70500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}