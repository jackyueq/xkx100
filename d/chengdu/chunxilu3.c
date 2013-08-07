// Room: /d/chengdu/chunxilu3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
�����ǳɶ�������ĵش���������·��������Ľֵ����ԣ�����
����������������·�漸�����ճ���Ӱ��·�ϵ�����Ħ����࣬����Ϊ
���Ե����Ʊ����š�һ�ɷ��٣������ľ��󡣲�Զ���Ĺ�����(sign)վ
�������¼���������������ʱ����Ŀ����㡣���Ϸ����ǳɶ���ĸ�׺�
--���Ϻӡ�
LONG);
	set("outdoors", "chengdu");
	set("objects", ([
		__DIR__"npc/weibing" : 2,
	]));
	set("exits", ([
		"southeast" : __DIR__"funanhe1",
		"north"     : __DIR__"chunxilu2",
	]));
	set("item_desc", ([ 
		"sign" : "�ɶ��󸮣��Ͻ�����������Ū�ף�\n",
	]));
	set("coor/x", -8060);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	if( userp(me) && dir == "north" && ob=present("wei bing",this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if((int)(inv[i]->query("weapon_prop")) &&
				(int)(inv[i]->query("equipped")))
				return notify_fail(ob->name()+ "����ȵ����������췴�����������ֱֳ������ܽ�ȥ��\n"); 
		}
	}
	return 1;
}

