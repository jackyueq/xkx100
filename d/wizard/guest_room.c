// /d/wizard/guest_room.c

#include <room.h>
inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "��ʦ�����");
	set("long", @LONG
��������ʦ����ҽ����ĵط����������ʲô������Ҫ����ʦ��
�̣���������������(post)�������������ǣ�浽���ջ����Ѿ��ڰ�
���ļ�������ϸ˵������ʦ�ǾͲ�һ����ش�¥������ʦ��Ϣ�ң�
һ����ҵ��������ϲ�ȥ�ˡ��������½���BUG�����ң�����з���
ʲôbug�������뿴������Ľ���������Թ�ȥ��䡣
LONG );

	set("exits", ([
		"up": __DIR__"wizard_room",
		"southeast": "/d/city/wumiao",
		"west" : __DIR__"bug_room",
        ]));
	set("item_desc", ([
		"up": "��Ҫ͵����\n",	
        ]));
//  set("objects", ([
//      "/clone/npc/qingyun" : 1,
//  ]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	create_door("southeast", "����", "northwest", DOOR_CLOSED);
	setup();
	call_other("/clone/board/towiz_b", "???");
	"/clone/npc/qingyun"->move(this_object());
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

