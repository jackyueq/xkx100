//Room: /d/dali/road2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ٵ�");
	set("long",@LONG
������᫵���·��Խ���ϵ�ɽ�������ϱ��������Ѿ������ƹ�
���ɽ����������������һ����Ȼ���ϸ������Ѻ����С�����������
����ɽ�����ɴ������ȥ��ɽ�����츮֮������·���Զ���һ����
�ʵĳ�ɽ����(mountain)�������಻���Ĵ�ɭ��(forest)��
LONG);
	set("outdoors", "dalin");
	set("item_desc",([
	"mountain" :
	   "�й������ϵĺ��ɽ����ɽ�ƶ��ͣ�����ǧ�ʵ��׳�գ�\n",
	"forest"   :
	   "���ɽ���������ľ������ԭʼɭ���ˡ����ڵ���̫��᫣����Բɷ���
ǧ��Ĳ����ľ��������Ƭɽ����\n",
	]));
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"road1",
	    "southwest"  : __DIR__"road3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}