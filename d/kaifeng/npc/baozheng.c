#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "bao zheng", "bao", "zheng" }));
        set("title", HIY "��ͼ��ѧʿ" NOR);
        set("gender", "����");
        set("age", 53);
        set("str", 20);
        set("dex", 20);
        set("long", "�����ǳ��е���ͼ��ѧʿ��ة�ࡣֻ������ɫ��\n"
                    "�ڣ���ò���棬���Ȳ��������㲻������������\n"
                    "����\n");
        set("combat_exp", 3000000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 15);

        set("neili", 500); 
        set("max_neili", 500);
        set("jiali", 10);

        setup();
        carry_object(CLOTH_DIR"jinpao")->wear();
}

